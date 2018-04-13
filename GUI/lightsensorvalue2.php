<?php
	$myfile = fopen("lightsensor2.txt", "r") or die("unable to open file!");
	$value = fread($myfile,filesize("lightsensor2.txt"));
	echo $value;
	fclose($myfile);
?>