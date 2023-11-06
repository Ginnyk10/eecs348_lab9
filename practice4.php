<!DOCTYPE html>
<html>

<head>
    <h1>Multiplication Table</h1>
</head>

<body>
<link href="styles.css" rel="stylesheet" type="text/css" />
    <?php
    if (isset($_POST["size"])) {
        $size = intval($_POST["size"]);
        if ($size > 0) {
            echo "<table border='1'>";
            echo "<tr><th></th>";

            for ($i = 1; $i <= $size; $i++) {
                echo "<th>" . $i . "</th>";
            }
            echo "</tr>";

            for ($i = 1; $i <= $size; $i++) {
                echo "<tr><th>" . $i . "</th>";
                for ($j = 1; $j <= $size; $j++) {
                    echo "<td>" . ($i * $j) . "</td>";
                }
                echo "</tr>";
            }
            echo "</table>";
        } else {
            echo "<p>Enter a valid number.</p>";
        }
    }
    ?>
</body>

</html>
