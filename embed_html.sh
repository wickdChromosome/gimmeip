
echo 'const char* get_html_template() { return ' > html_content.h
cat input_html.html | sed 's/^/"/' | sed 's/$/"/' >> html_content.h
echo ";}" >> html_content.h 

