<form action="sell.php" method="post">
<fieldset>
    <body style="background-color: #FFFAFA">    
    <div class="form-group">
    <select class="form-control", name = "symbol">
    <option value = "symbol">Stock Symbol</option>
    <?php
        foreach($symbols as $symbol)
        {
            echo "<option value='".$symbol["symbol"]."'>".$symbol["name"]."</option>";            
        }
    ?>
    </select>
    </div>
    
    <div class="form-group">
                <input class="form-control" name="shares" placeholder="Shares to Sell" type="code"/>
    </div>
    
       
    <div class="form-group">
    <button class="btn btn-default" type="submit">
        <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
            Sell
        </button>
    </div>
    <img src= "http://talk.payloadz.com/wp-content/uploads/2013/12/Selling-Digital-Downloads-With-PayPal-660x320.jpg" style = "width: 700x; height: 200px"/>
</fieldset>
</form>