<?php
	$myfile = fopen("lightsensor4.txt", "r") or die("unable to open file!");
	$value = fread($myfile,filesize("lightsensor4.txt"));
	echo $value;
	fclose($myfile);
?>