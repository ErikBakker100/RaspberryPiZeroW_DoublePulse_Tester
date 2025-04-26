
# Naam van de output
TARGET = notmain

# Toolchain
CROSS_COMPILE=arm-none-eabi-
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
AS=$(CROSS_COMPILE)as
OBJDUMP=$(CROSS_COMPILE)objdump
OBJCOPY=$(CROSS_COMPILE)objcopy
# Compileeropties
CFLAGS = -Wall -O2 -nostdlib -nostartfiles -ffreestanding -Ilib
ASFLAGS= --warn --fatal-warnings
LDFLAGS = -T memmap.ld

SHELL := cmd.exe

RM = del /q
NULL := nul

C_FILES := $(shell for /R src %%f in (*.c) do @echo %%f)
C_FILES += $(shell for /R lib %%f in (*.c) do @echo %%f)
AS_FILES := $(shell for /R src %%f in (*.s) do @echo %%f)

# Zet de .c en .s bestanden om naar .o bestanden
C_OBJS = $(C_FILES:.c=.o)
ASM_OBJS = $(AS_FILES:.s=.o)

# Bestanden (Combineer alle objectbestanden)
OBJS = $(C_OBJS) $(ASM_OBJS)

# Standaardregel
all: $(TARGET).elf kernel.img kernel.list

$(TARGET).elf: $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $@

# Compileer C-bestanden
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Assembleer ASM-bestanden
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

# Genereer kernel.img (binair image)
kernel.img: $(TARGET).elf
	$(OBJCOPY) --srec-forceS3 $(TARGET).elf -O srec $(TARGET).srec
	$(OBJCOPY) $(TARGET).elf -O binary kernel.img

kernel.list: $(TARGET).elf
	$(OBJDUMP) -d -S -C -l $< > $@

clean:
#	$(RM) $(TARGET).elf $(TARGET).bin $(TARGET).img $(TARGET).srec $(C_OBJS) $(ASM_OBJS)
	-$(RM) $(TARGET).elf $(TARGET).bin $(TARGET).img $(TARGET).srec 2> $(NULL)
	-$(RM) $(OBJS) 2> $(NULL)
