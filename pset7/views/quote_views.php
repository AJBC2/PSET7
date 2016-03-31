<h3><?= $stock["symbol"] ?></h3>
<h2><?= $stock["name"] ?></h2>
Price: $<?= $stock["price"] ?>

<?php
    CS50::query("INSERT INTO quote (user_id, quote) VALUES(?, ?)", $_SESSION["id"], strtoupper($stock["symbol"]));
?>

<p>
    
</p>

<div class="form-group">
    <button onClick="window.location='buydirect.php';" <button class="btn btn-default" type="submit">
        <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span> Buy This Stock</button>
</div>