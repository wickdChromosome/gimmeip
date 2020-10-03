
echo 'char* get_html_template() { return "\' > html_content.h
cat input_html.html | sed 's/$/\\/g' >> html_content.h 
echo '";}' >> html_content.h 

