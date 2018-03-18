R"(
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
<script> function makeAjaxCall(url){$.ajax({"url": url})}</script>
</head>
<body>
</br>
<div class="container-fluid">
<!-- Power Controls -->
<div class="row" style="padding-bottom:1em">
<div class="col-xs-4">
    <button id="dth" type="button" class="btn btn-danger btn-sm" style="width: 100%" onclick='makeAjaxCall("dth")'>DTH</button>
</div>
<div class="col-xs-4">
    <button id="av" type="button" class="btn btn-success btn-sm" style="width: 100%" onclick='makeAjaxCall("av")'>AV</button>
</div>
<div class="col-xs-4">
    <button id="tv" type="button" class="btn btn-danger btn-sm" style="width: 100%" onclick='makeAjaxCall("tv")'>TV</button>
</div>
</div>
<!-- Channel Controls -->
<div class="row" style="padding-bottom:1em">
<div class="col-xs-4">
    <button id="ch1" type="button" class="btn btn-warning btn-sm" style="width: 100%" onclick='makeAjaxCall("ch1")'>Sony</button>
</div>
<div class="col-xs-4">
    <button id="ch2" type="button" class="btn btn-warning btn-sm" style="width: 100%" onclick='makeAjaxCall("ch2")'>NDTV</button>
</div>
<div class="col-xs-4">
    <button id="ch3" type="button" class="btn btn-warning btn-sm" style="width: 100%" onclick='makeAjaxCall("ch3")'>OTV</button>
</div>
</div>
<!-- DTH Controls -->
<div class="row" style="padding-bottom:1em">
<div class="col-xs-offset-4 col-xs-4">
    <button id="n" type="button" class="btn" style="width: 100%" onclick='makeAjaxCall("n")'><span class="glyphicon glyphicon-triangle-top"></span></button>
</button>
</div>
</div>
<div class="row" style="padding-bottom:1em">
<div class="col-xs-4">
    <button id="w" type="button" class="btn" style="width: 100%" onclick='makeAjaxCall("w")'><span class="glyphicon glyphicon-triangle-left"></span></button>
</button>
</div>
<div class="col-xs-4">
    <button id="ok" type="button" class="btn" style="width: 100%" onclick='makeAjaxCall("ok")'>OK</button>
</div>
<div class="col-xs-4">
    <button id="e" type="button" class="btn" style="width: 100%" onclick='makeAjaxCall("e")'><span class="glyphicon glyphicon-triangle-right"></span></button>
</button>
</div>
</div>
<div class="row" style="padding-bottom:1em">
<div class="col-xs-offset-4 col-xs-4">
    <button id="s" type="button" class="btn" style="width: 100%" onclick='makeAjaxCall("s")'><span class="glyphicon glyphicon-triangle-bottom"></span></button>
</button>
</div>
</div>
<div class="row" style="padding-bottom:1em">
<div class="col-xs-4">
    <button id="back" type="button" class="btn btn-warning btn-xs" style="width: 100%" onclick='makeAjaxCall("back")'><span class="glyphicon glyphicon-arrow-left"></span></button>
</button>
</div>
<div class="col-xs-4">
    <button id="close" type="button" class="btn btn-danger btn-xs" style="width: 100%" onclick='makeAjaxCall("close")'><span class="glyphicon glyphicon-remove"></span></button>
</button>
</div>
<div class="col-xs-4">
    <button id="menu" type="button" class="btn btn-danger btn-xs" style="width: 100%" onclick='makeAjaxCall("menu")'><span class="glyphicon glyphicon-th-list"></span></button>
</button>
</div>
</div>
<!-- Channel/Volume Controls -->
<div class="row" style="padding-bottom:1em">
<div class="col-xs-4">
    <button id="chnup" type="button" class="btn btn-primary" style="width: 100%" onclick='makeAjaxCall("chnup")'><span class="glyphicon glyphicon-plus"></span></button>
</button>
</div>
<div class="col-xs-4">
    <button id="mute" type="button" class="btn btn-danger" style="width: 100%" onclick='makeAjaxCall("mute")'><span class="glyphicon glyphicon-volume-off"></span></button>
</button>
</div>
<div class="col-xs-4">
    <button id="volup" type="button" class="btn btn-primary" style="width: 100%" onclick='makeAjaxCall("volup")'><span class="glyphicon glyphicon-volume-up"></span></button>
</button>
</div>
</div>
<div class="row" style="padding-bottom:1em">
<div class="col-xs-4">
    <button id="chndn" type="button" class="btn btn-primary" style="width: 100%" onclick='makeAjaxCall("chndn")'><span class="glyphicon glyphicon-minus"></span></button>
</button>
</div>
<div class="col-xs-4">
    <button id="info" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("info")'><span class="glyphicon glyphicon-info-sign"></span></button>
</button>
</div>
<div class="col-xs-4">
    <button id="voldn" type="button" class="btn btn-primary" style="width: 100%" onclick='makeAjaxCall("voldn")'><span class="glyphicon glyphicon-volume-down"></span></button>
</button>
</div>
</div>
<div class="row" style="padding-bottom:1em">
<div class="col-xs-3">
    <button id="red" type="button" class="btn btn-danger btn-xs" style="width: 100%" onclick='makeAjaxCall("red")'>&nbsp;</button>
</div>
<div class="col-xs-3">
    <button id="green" type="button" class="btn btn-success btn-xs" style="width: 100%" onclick='makeAjaxCall("green")'>&nbsp;</button>
</div>
<div class="col-xs-3">
    <button id="yellow" type="button" class="btn btn-warning btn-xs" style="width: 100%" onclick='makeAjaxCall("yellow")'>&nbsp;</button>
</div>
<div class="col-xs-3">
    <button id="blue" type="button" class="btn btn-primary btn-xs" style="width: 100%" onclick='makeAjaxCall("blue")'>&nbsp;</button>
</div>
</div>
<!-- Numbers -->
<div class="row" style="padding-bottom:1em">
<div class="col-xs-4">
    <button id="c1" type="button" class="btn btn-infobtn btn-info" style="width: 100%" onclick='makeAjaxCall("c1")'>1</button>
</div>
<div class="col-xs-4">
    <button id="c2" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("c2")'>2</button>
</div>
<div class="col-xs-4">
    <button id="c3" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("c3")'>3</button>
</div>
</div>
<div class="row" style="padding-bottom:1em">
<div class="col-xs-4">
    <button id="c4" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("c4")'>4</button>
</div>
<div class="col-xs-4">
    <button id="c5" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("c5")'>5</button>
</div>
<div class="col-xs-4">
    <button id="c6" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("c6")'>6</button>
</div>
</div>
<div class="row" style="padding-bottom:1em">
<div class="col-xs-4">
    <button id="c7" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("c7")'>7</button>
</div>
<div class="col-xs-4">
    <button id="c8" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("c8")'>8</button>
</div>
<div class="col-xs-4">
    <button id="c9" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("c9")'>9</button>
</div>
</div>
<div class="row" style="padding-bottom:1em">
<div class="col-xs-4">
    <button id="x" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("x")'>&#8727;</button>
</div>
<div class="col-xs-4">
    <button id="c0" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("c0")'>0</button>
</div>
<div class="col-xs-4">
    <button id="hash" type="button" class="btn btn-info" style="width: 100%" onclick='makeAjaxCall("hash")'>#</button>
</div>
</div>
</body>
</html>
)"
