BUILD_DIR = build

######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og
#

TARGET = domzad2_program



SOURCES_S = \
startup_code.s \


SOURCES_C = \
Src/main.c \
Src/util.c \
Src/timer_pwm.c \
Src/adc.c \
Src/usart.c


#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m3

# fpu
# NONE for Cortex-M0/M0+/M3

# float-abi


# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  


# AS includes
AS_INCLUDES =  

# C includes
C_INCLUDES =  \
-IInc \

# compile gcc flags
#ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

#CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections -mlong-calls

#ifeq ($(DEBUG), 1)
#CFLAGS += -g -gdwarf-2 -fdebug-prefix-map==../
#endif

# Generate dependency information
#CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


LINKER_SCRIPT = linker_script.ld
#LINKER_SCRIPT = STM32F103R6Tx_FLASH.ld

PREFIX = D:\toolchain\GNU MCU Eclipse\ARM Embedded GCC\8.3.1-1.1\bin

CC = $(PREFIX)/arm-none-eabi-gcc.exe -c
AS = $(PREFIX)/arm-none-eabi-as.exe
LD = $(PREFIX)/arm-none-eabi-ld.exe
OBJCOPY = $(PREFIX)/arm-none-eabi-objcopy.exe

MCU = -mcpu=cortex-m3 -mthumb

OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES_S:.s=.o))
vpath %.s $(sort $(dir $(SOURCES_S)))

OBJECTS += $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES_C:.c=.o)))
vpath %.c $(sort $(dir $(SOURCES_C)))

all : $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex

$(BUILD_DIR)/$(TARGET).elf : $(OBJECTS) makefile
	$(LD) -T $(LINKER_SCRIPT) -o $(@) $(OBJECTS)

$(BUILD_DIR)/$(TARGET).hex : $(BUILD_DIR)/$(TARGET).elf | $(BUILD_DIR)
	$(OBJCOPY) --output-target ihex $(<) $(@)

#$(BUILD_DIR)/%.o: %.s makefile | $(BUILD_DIR)
#	$(AS) -c $(CFLAGS) $< -o $@
$(BUILD_DIR)/%.o : %.s makefile | $(BUILD_DIR)
	$(AS) $(MCU) $(C_INCLUDES) -o $(@) $(<)

#$(BUILD_DIR)/%.o: %.c makefile | $(BUILD_DIR) 
#	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o : %.c makefile | $(BUILD_DIR)
	$(CC) $(MCU) $(C_INCLUDES) -o $(@) $(<)

$(BUILD_DIR) :
	mkdir $(@)

clean :
	rm -rf $(BUILD_DIR)
