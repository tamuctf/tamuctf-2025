<?php
function decrypt_text($enctext, $key) {
    $cipher = 'aes-256-ctr';
    $data = hex2bin($enctext);
    $ivLength = openssl_cipher_iv_length($cipher);
    $iv = substr($data, 0, $ivLength);
    $ciphertext = substr($data, $ivLength);
    return openssl_decrypt($ciphertext, $cipher, $key, OPENSSL_RAW_DATA, $iv);
}

$enctext = '4a75dc3343fcaaea2543513f6acedcf38c452ae7dc59a55ec143151007fe153639c2fb05bbd039487bf1b4bf2921a66b53e19aea707f1ac28c50c052ade3e494bb3c57e3703608509c96752e34d20337bae4a5192df2fffac1d791af64ca2dbfd40a7b7a69da034d17aabba9f3476c09b5a5035848d263e8e4cc03a0ac07c1af783f4d639c9878cabf31f37621163dcb5f9f5842a2236c30ada28b65a51948794a2186214c139aebb50e8a3988aba1d98107284080f3a9';

echo decrypt_text($enctext, 'cc4f3521e8be5cddf4897281d44d66e4950900667d9f2e739a90811ab4dba788');
?>
