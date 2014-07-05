# Folders containing files
INCLUDES	:= include
SOURCES		:= src
RESOURCES	:= res
BUILD		:= build

# Compiler
export LD := $(CXX)
# Compiler flags
CPPFLAGS=-O2 -g -W -Wall -pedantic -ansi -Wno-long-long -std=c++0x -Wextra -Wshadow
# Linking flags
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# Target program name = directory name
TARGET := $(notdir $(CURDIR))
# Automatically build a list of object files
CPPFILES := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
HPPFILES := $(foreach dir,$(INCLUDES),$(wildcard $(dir)/*.h))
# Object files
export OFILES := $(addprefix $(BUILD)/,$(CPPFILES:.cpp=.o))

# Source files
CPPFILES := $(addprefix $(SOURCES)/,$(CPPFILES))
# Build a list of include paths
export INCLUDE := $(foreach dir,$(INCLUDES), -I$(CURDIR)/$(dir)) -I$(CURDIR)/$(BUILD)

all: main

$(BUILD)/%.o:$(SOURCES)/%.cpp
	@mkdir -p $(BUILD)
	@echo Building $^ ...
	@$(LD) $(CPPFLAGS) -c $^ -o $@ $(INCLUDE)

main:$(OFILES) $(HPPFILES)
	@mkdir -p $(BUILD)
	@echo Linking necessary libraries...
	@$(LD) $(OFILES) $(CPPFLAGS) $(LDFLAGS) -o $(TARGET)
	@echo Built executable "$(TARGET)"

clean:
	@echo Cleaning...
	@rm -rf $(BUILD)/
	@rm -f $(TARGET)
	@rm -f $(TARGET).exe
	@rm -f *.dll
	@rm -f LICENSES.txt
