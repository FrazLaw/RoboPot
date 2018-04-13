<?php
	$myfile = fopen("lightsensor3.txt", "r") or die("unable to open file!");
	$value = fread($myfile,filesize("lightsensor3.txt"));
	echo $value;
	fclose($myfile);
?>