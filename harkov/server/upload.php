<?php
	if (isset($_SERVER['X-mac-addr']))
		$mac = $_SERVER['X-mac-addr'];
	else
		$mac = '00-00-00';
		
	$log = fopen('out.log', 'w+');
	fputs($log, $mac);
	if (isset($_FILES)) {
		foreach ($_FILES as $k => $v) {
			fputs($log, $k.'='.$v);
		}
	}
	fclose($log);
	//move_uploaded_file($_FILES['file']["tmp_name"], 'doclist'.$mac.'.txt');
	echo('ok');
?>