<?php
require_once 'vendor/autoload.php';

use Ramsey\Uuid\Uuid;

$serverKey = getenv('SERVER_KEY');

function encrypt_file($inputPath, $outputPath, $key) {
    exec("openssl enc -aes-256-ctr -salt -pbkdf2 -in $inputPath -out $outputPath -pass pass:$key");
}

function decrypt_file($path, $key) {
    return shell_exec("openssl enc -d -aes-256-ctr -pbkdf2 -in $path -out /dev/stdout -pass pass:$key");
}

function encrypt_text($plaintext, $key) {
    $cipher = 'aes-256-ctr';
    $iv = random_bytes(openssl_cipher_iv_length($cipher));
    $ciphertext = openssl_encrypt($plaintext, $cipher, $key, OPENSSL_RAW_DATA, $iv);
    return bin2hex($iv . $ciphertext);
}

function decrypt_text($enctext, $key) {
    $cipher = 'aes-256-ctr';
    $data = hex2bin($enctext);
    $ivLength = openssl_cipher_iv_length($cipher);
    $iv = substr($data, 0, $ivLength);
    $ciphertext = substr($data, $ivLength);
    return openssl_decrypt($ciphertext, $cipher, $key, OPENSSL_RAW_DATA, $iv);
}

function init_session() {
    global $serverKey;
    session_start();

    if (!isset($_SESSION['uuid'])) {
        $uuid = Uuid::uuid4()->toString();
        $_SESSION['uuid'] = encrypt_text($uuid, $serverKey);
    }
    if (!isset($_SESSION['key'])) {
        $key = bin2hex(random_bytes(32));
        $_SESSION['key'] = encrypt_text($key, $serverKey);
    }
    if (!isset($_SESSION['latex'])) {
        $latex = file_get_contents('template.tex');
        $_SESSION['latex'] = encrypt_text($latex, $serverKey);
    }
}
?>
