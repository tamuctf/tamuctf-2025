<?php
require_once 'helper.php';

init_session();

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (empty($_POST['latex'])) {
        http_response_code(400);
        echo 'Bad Request: Missing LaTeX.';
        exit;
    }

    $_SESSION['latex'] = encrypt_text($_POST['latex'], $serverKey);
}
?>
