CFLAGS=-pthread

gimmeip_server:  
	bash ./embed_html.sh && gcc $(CFLAGS) gimmeip_server.c -o gimmeip_server
