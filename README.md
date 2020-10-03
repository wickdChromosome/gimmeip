# gimmeip.org

## Description 
Intended to be an easy way to get your public IP address from a terminal, for use in scripts(check to make sure VPN works, etc) for example. To get your public IP, you can do:
```
my_ip=$(curl gimmeip.org) && echo $my_ip
127.0.0.1
```

The webapp also serves a webpage if you directly visit the url.

## Compilation
To compile the project, simply do:
```
make
```
in the project directory.

For the debug build, you can do:
```
make debug
```

## Configuration
You can configure the port and host address using the macros in the gimmeip_server.c file.
The input_html.html file contains the html for the page to be served. The embed_html.sh script converts this to a stack allocated string during compilation, and this acts as a template for all the other webpages to be served.
