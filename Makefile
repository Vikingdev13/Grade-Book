repl-build.out: gradebook_template.c
	gcc -o $@ $^

.PHONY: run
run: repl-build.out
	./$^

.PHONY: clean

clean:
	rm -f repl-build.out