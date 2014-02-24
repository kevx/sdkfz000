<?php
	print_r($_SERVER);
	if (isset($_SERVER['HTTP_X_MAC_ADDR']))
		$mac = $_SERVER['HTTP_X_MAC_ADDR'];
	else
		$mac = '00-00-00';
		
	$log = fopen('out.log', 'w+');
	fputs($log, $mac);
	if (isset($_FILES)) {
		foreach ($_FILES as $k => $v) {
			fputs($log, $k.'='.$v);
		}
	} else {
	}
	fclose($log);
	move_uploaded_file($_FILES['file']["tmp_name"], 'doclist'.$mac.'.txt');
	echo('ok');
?>