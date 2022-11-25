


caesar: main.o
	gcc -o caesar main.o

main.o : main.c
	gcc -c main.c



. PHONY : install
install : caesar
	sudo cp caesar /bin/
	sudo chmod 555 /bin/caesar
	sudo chown root:root /bin/caesar

. PHONY : clean
clean:
	rm *.o
	rm caesar