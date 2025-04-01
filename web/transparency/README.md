# Transparency

Author: `k.nix`

I created my own private document sharing site with a novel twist to increase the security boundaries between shared links.

## Dev Notes

This challenge is not truly solvable outside of real infrastructure as it requires SSL certificates to be generated.

Depending on how requests are forwarded, the port number in the `SERVER_NAME` config may need to be adjusted.

For the two secret subdomains (`tve987yv` and `g64aes8z`), infrastructure must create individual/non-wildcard certificates, but forward the transparency subdomains using wildcards in DNS. This prevents the challenge from being solvable via DNS records, where most competitors would likely check first.

## Solution

We can look up certificates for the domain at https://crt.sh/?q=CYBR.club. The flag is visible on the `tve987yv` subdomain: https://tve987yv.transparency.cybr.club/.

flag:
`gigem{CT_15_41w4y5_w47ch1n9}`
