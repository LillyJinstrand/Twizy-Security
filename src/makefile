GPR=security.gpr

.PHONY: spark
spark:
	mkdir -p obj
	gnatmake -P$(GPR)

.PHONY: prove
prove:
	gnatprove -j 0 --level=4 -P$(GPR)
.PHONY: clean
clean:
	rm -rf gnatprove
	rm -rf obj/*
