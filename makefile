all:
	gcc rm.c -o xrm
	gcc date.c -o xdate
	gcc ls.c -o xls
	gcc cat.c -o xcat
	gcc mkdir.c -o xmkdir
	gcc Shell.c -o Shell
clean:
	rm xrm
	rm xdate
	rm xls
	rm xcat
	rm Shell
	rm xmkdir