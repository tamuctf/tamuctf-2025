LOOP_DEV := $(shell (sudo losetup -j disk.img && sudo losetup -f) | head -n 1 | cut -d":" -f1)

all: disk.img

clean:
	# sorry, has to be done
	sudo rm -rf linux rootfs initramfs.img.lz4 mnt chroot disk.img sleep.tar bzImage

run-1: disk.img initramfs.img.lz4
	sudo qemu-system-x86_64 -kernel bzImage -initrd initramfs.img.lz4 -append "earlyprintk=serial,ttyS0 console=ttyS0" -drive "file=disk.img,format=raw,snapshot=on" -drive "file=crontab-1,format=raw,snapshot=on" -drive "file=flag-1.txt,format=raw,snapshot=on" -monitor none -display none -serial stdio -m 256M -accel kvm

run-2: disk.img initramfs.img.lz4
	sudo qemu-system-x86_64 -kernel bzImage -initrd initramfs.img.lz4 -append "earlyprintk=serial,ttyS0 console=ttyS0" -drive "file=disk.img,format=raw,snapshot=on" -drive "file=crontab-2,format=raw,snapshot=on" -drive "file=flag-2.txt,format=raw,snapshot=on" -monitor none -display none -serial stdio -m 256M -accel kvm

sleep.tar: sleep.c Dockerfile.inner
	docker build -f Dockerfile.inner -t sleep .
	docker save sleep > sleep.tar
	docker rmi sleep

linux:
	git clone --branch v6.7 --depth 1 https://github.com/torvalds/linux.git

bzImage: linux linux.config
	cp linux.config linux/.config
	make -j $(nproc) -C linux modules bzImage
	cp linux/arch/x86_64/boot/bzImage .

chroot: bzImage inittab setup-autologin
	mkdir -p chroot
	sudo ./alpine-chroot-install -i '/tmp' -b v3.19 -d "$(shell realpath chroot)" -p docker -p openrc -p cronie -p fuse-overlayfs -p iptables-legacy -p alpine-sdk
	./chroot/destroy
	sudo touch chroot/etc/network/interfaces
	sudo cp inittab chroot/etc/inittab
	sudo cp setup-autologin chroot/usr/sbin/autologin
	sudo ln -sf iptables-legacy chroot/sbin/iptables
	sudo ln -sf iptables-legacy-restore chroot/sbin/iptables-restore
	sudo ln -sf iptables-legacy-save chroot/sbin/iptables-save
	sudo chroot chroot rc-update add docker default
	sudo make -j $(nproc) -C linux modules_install INSTALL_MOD_PATH=../chroot

disk.img: chroot sleep.tar initramfs.img.lz4
	fallocate -l 2G disk.img
	(echo g; echo n; echo; echo; echo; echo w) | fdisk disk.img
	sudo losetup --direct-io=on -PL $(LOOP_DEV) disk.img || true
	sudo mkfs.ext4 $(LOOP_DEV)p1
	mkdir -p mnt
	sudo mount $(LOOP_DEV)p1 mnt
	sudo cp -r chroot/* mnt
	sudo umount mnt
	sudo qemu-system-x86_64 -kernel bzImage -initrd initramfs.img.lz4 -append "earlyprintk=serial,ttyS0 console=ttyS0" -drive "file=$(LOOP_DEV),format=raw" -drive "file=sleep.tar,format=raw,snapshot=on" -monitor none -display none -serial stdio -accel kvm
	sudo mount $(LOOP_DEV)p1 mnt
	sudo cp autologin mnt/usr/sbin/autologin
	sudo umount mnt
	sudo losetup -d $(LOOP_DEV)

rootfs:
	mkdir rootfs
	curl https://dl-cdn.alpinelinux.org/alpine/v3.20/releases/x86_64/alpine-minirootfs-3.20.3-x86_64.tar.gz | tar xz -C rootfs

initramfs.img.lz4: rootfs init
	cp init rootfs/
	cd rootfs && find . -print0 | cpio --null --create --verbose --owner root:root --format=newc | lz4c -l > ../initramfs.img.lz4
