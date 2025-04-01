<?php
require_once 'helper.php';

init_session();
$latex = decrypt_text($_SESSION['latex'], $serverKey);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Research</title>
    <link rel="stylesheet" href="static/style.css">
</head>
<body>
    <div class="container">
        <h1>Online LaTeX Editor and Compiler</h1>
        <div class="panes">
            <div class="editor" id="editor"></div>
            <div class="result">
                <button onclick="compile()">Compile</button>
                <iframe id="result" src="compile.php" width="100%" height="100%" frameborder="0"></iframe>
            </div>
        </div>
        <script src="static/cm6.bundle.min.js"></script>
        <script>
            async function compile() {
                const data = new URLSearchParams();
                data.append('latex', view.state.doc.toString());
                
                await fetch("/update.php", {
                    method: "POST",
                    headers: {"Content-Type": "application/x-www-form-urlencoded"},
                    body: data.toString()
                });

                let iframe = document.getElementById("result");
                iframe.contentWindow.location.reload();
            }

            const initialState = cm6.createEditorState(<?= json_encode($latex) ?>);
            const view = cm6.createEditorView(initialState, document.getElementById("editor"));

            document.addEventListener('keydown', function(e) {
                if (e.ctrlKey && e.key === 's') {
                    e.preventDefault();
                    compile();
                }
            });
        </script>
    </div>
</body>
</html>
