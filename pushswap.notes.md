# pushswap

## Requirements

**allowed external functions:** `read`, `write`, `malloc`, `free`, `exit`

**global variables:** disallowed

**input:** stack formatted as list of **integers**, with the first being the top of the stack

**return:**
- on success: list of instructions as strings separated by `'\n'`
	if no parameters are given, the program doesn't display anything, just exits
	if the list is already sorted as well
- on error: `"Error\n"` on `stderr`
	Errors: invalid arguments (non integers, too big integers, duplicates)

**readme:** standard minimum: description, instruction, resources
