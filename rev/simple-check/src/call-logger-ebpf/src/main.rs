#![no_std]
#![no_main]

use aya_ebpf::{macros::uprobe, programs::ProbeContext, EbpfContext};
use aya_log_ebpf::info;

#[uprobe]
pub fn call_logger(ctx: ProbeContext) -> u32 {
    try_call_logger(ctx).unwrap_or_else(|ret| ret)
}

fn try_call_logger(ctx: ProbeContext) -> Result<u32, u32> {
    info!(&ctx, "function called in pid {}", ctx.pid());
    Ok(0)
}

#[cfg(not(test))]
#[panic_handler]
fn panic(_info: &core::panic::PanicInfo) -> ! {
    loop {}
}
