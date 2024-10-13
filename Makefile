all:
	@g++ -o database ./source_files/add.cpp ./source_files/delete.cpp ./source_files/encryption.cpp ./source_files/functions.cpp ./source_files/main.cpp ./source_files/menu.cpp ./source_files/search.cpp ./source_files/update.cpp ./source_files/view.cpp
	@./database
.PHONY: clean
clean:
	@rm -f database