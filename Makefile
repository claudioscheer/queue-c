default: program 

program:
	@echo "Compiling..." 
	@g++ main.c -o main
	@echo "Running...\n"
	@./main

test:
	@g++ test.c -o test
	@./test

clean:
	rm -f main
