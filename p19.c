printf("\nPointer subscript notation\n");
for (i = 0; i < 4; i++)
{
	printf("bPtr[%d]=%d\n", i, bPtr[i]);
}

printf("\nPointer/offset notation\n");
for (offset = 0; offset < 4; offset++)
{
	printf("*(bPtr+%d)=%d\n", offset, *(bPtr + offset));
}
system("pause");
return 0;
}