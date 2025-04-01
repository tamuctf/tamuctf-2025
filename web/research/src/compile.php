<?php
require_once 'vendor/autoload.php';
require_once 'helper.php';

use Ramsey\Uuid\Uuid;

function return_pdf($pdf) {
    header('Content-Type: application/pdf');
    header('Content-Disposition: inline; filename="paper.pdf"');
    echo $pdf;
    exit;
}

init_session();

$compUuid = Uuid::uuid4()->toString();
$sessUuid = decrypt_text($_SESSION['uuid'], $serverKey);
$key = decrypt_text($_SESSION['key'], $serverKey);
$latex = decrypt_text($_SESSION['latex'], $serverKey);
$dir = "/var/tmp/$compUuid";

chdir('/tmp');
if (
    file_exists("$sessUuid.tex.enc") && 
    file_exists("$sessUuid.text.enc") &&
    decrypt_text("$sessUuid.tex.enc", $key) == $latex
) {
    return_pdf(decrypt_file("$sessUuid.pdf.enc", $key));
}

exec("mkdir $dir");
$texFile = fopen("$dir/paper.tex", 'w');
if ($texFile) {
    fwrite($texFile, $latex);
    fclose($texFile);
}

exec("pdflatex -halt-on-error -output-directory $dir $dir/paper.tex", $output, $returnCode);
if ($returnCode !== 0) {
    http_response_code(400);
    echo 'Compilation failed.';
    exit;
}

encrypt_file("$dir/paper.pdf", "$sessUuid.pdf.enc", $key);
encrypt_file("$dir/paper.tex", "$sessUuid.tex.enc", $key);
exec("rm -rf $dir");
return_pdf(decrypt_file("$sessUuid.pdf.enc", $key));
?>
