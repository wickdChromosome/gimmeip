CCFLAGS=-pthread

all: gimmeip_server

debug: CCFLAGS += -DDEBUG -g
debug: gimmeip_server

gimmeip_server:  
	bash ./embed_html.sh && $(CC) $(CCFLAGS) gimmeip_server.c -o gimmeip_server
