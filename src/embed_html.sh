
echo 'char* get_html_template() { return "\' > html_content.c
cat input_html.html | sed 's/$/\\/g' >> html_content.c 
echo '";}' >> html_content.c 

