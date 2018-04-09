<?php
	$myfile = fopen("position.txt","r") or die("Unable to open file!");
	$value = fread($myfile, filesize("position.txt"));
	echo json_encode($value);
	fclose($myfile);
?>
