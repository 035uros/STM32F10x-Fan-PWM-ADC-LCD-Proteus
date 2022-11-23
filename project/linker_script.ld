_msp_stack_pointer = 0x20002800;

MEMORY
{
	FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 32K
	SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 10K
}

SECTIONS
{
	.output_vector_table :
	{
		*(.vector_table)
	} > FLASH
	
	.output_text :
	{
		*(.text)
		*(.text*)
	} > FLASH
	
	.output_data :
	{
		_vma_data_start = .;
		*(.data)
		*(.data*)
		_vma_data_end = .;
	} > SRAM AT > FLASH
	
	_lma_data_start = LOADADDR(.output_data);
	
	.output_bss :
	{
		*(.bss)
		*(.bss*)
	} > SRAM
	
}