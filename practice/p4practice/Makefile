all: str
clean: 
	find . -type f -executable -exec rm '{}' \;
retry: 
	find . -type f -executable -exec rm '{}' \;
	make all
str: 
	gcc -Wall stringPractice.c -o str

.PHONY: all clean retry
