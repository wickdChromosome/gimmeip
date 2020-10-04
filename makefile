CCFLAGS=-pthread 

all: bin/gimmeip_server

debug: CCFLAGS += -DDEBUG -g
debug: bin/gimmeip_server

bin/gimmeip_server:  
	mkdir -p bin
	cd src && bash embed_html.sh && \
	$(CC) $(CCFLAGS) gimmeip_server.c html_content.c -o ../bin/gimmeip_server

