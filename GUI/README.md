# Web Page GUI - Team RoboPot

Hello!

Welcome to the web page directory for team RoboPot! This readme file is going to explain how to get this web page up and running as well as explaining some of the main factors when creating and compiling it.

If you're like myself and new to web page development, the best way to learn is to start working on your own web page for a hobbyist project like ours. There are great resources out there such as W3Schools to help you out as well!

### Defining features

The main requirements of the GUI were to:</br>
-Show the position of the robot.</br>
-Take a user input, via a button press, and store the request on the server.</br>
-Display the light sensor values in real-time. 

So, as detailed on the front page, the button interface is a simple 4x4 button array with each button having it's own element ID wich enables a JavaScript function to create a value stored on the Pi. To take a client side button press and convert it to a stored value on the Pi, AJAX (Asynchronous JavaScript and XML) was used. Below is a snippet of code to demonstrate how the http request was generated and handled. 

```html
<script type="text/javascript">	 //script attribute 
function lightsensing(){
	setInterval(function(){ //wait function 
		var request = new XMLHttpRequest(); //XMLHttpRequest is in-built function to request data from the server and dynamically update the wep page
		request.onreadystatechange = function(){
		if (request.readyState == 4 && request.status == 200){ //server status and checks 
				console.log(request.responseText); //console.log stores the value being transferred and is used for debugging purposes
				document.getElementById("demo").innerHTML =  request.responseText; //document is assigning the value from above into the table 
			}
		}
		request.open('POST', 'lightsensorvalue1.php', true); //actually opening and sending the files, utilising the php script
		request.send();
	},1000);
}	//wait
</script>
```
AJAX provides the bridge between the server and the client in an easy and dynamic way. It allows us to run PHP scripts which can handle server side files such as the light sensor values and position - both stored in text files. PHP was the second major language utilised in this project to open, read and then close the storage text files. Below is a sample PHP script:

```php
<?php
	$myfile = fopen("position.txt","r") or die("Unable to open file!");
	$value = fread($myfile, filesize("position.txt"));
	echo json_encode($value);
	fclose($myfile);
?>
```

An interesting note about this script in particular, is that JSON_encode needed to be used on the object value being produced by the PHP script. This caused confusion when processing the variable wiht JavaScript so it neeeded to be transformed into a simple JSON fortmat in order to be used.

Languages used:
PHP, JavaScript, HTML, CSS.

### Graphical Demonstration

To view the page without setting up your own html file, just click the link to simulate the graphical output of the web page: https://jsfiddle.net/FrazLaw/uL4w2nnj/1/

### How-to Build the Web Page

To open this web page in your browser you'll need to create a simple text document on your computer. You can also use a text editor such as Notepad++ and choose to save the file with a html extension. This will store the program in a file under your default web application such as google chrome and enable you to easily open it as you would any normal internet browser.

Resources for initial developemnt or changes:
https://www.w3schools.com/html/default.asp
