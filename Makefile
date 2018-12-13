CC := gcc
CFLAGS := -g
LINKFLAGS := -std=c99 -lpthread -lm -lSDL2_image `sdl2-config --cflags --libs` 
RM := rm
.PHONY: $(TARGET)
.PHONY: clean

MKDIR_P := mkdir -p

VPATH := ./src/ ./obj/ ./includes/ 

SRC_PATH := ./src/
OBJ_PATH := ./obj/
INC_PATH := -I ./includes

COMPONENTS_SRC := ./src/components/

UTILITY_SRC := ./src/utils/

TARGET := breakout




COMPONENT_OBJS := 	transformComponent.o \
					spriteComponent.o \
					colliderComponent.o \
					keyboardComponent.o
OBJ1 :=  main.o \
		 vector2D.o \
		 manager.o \
		 entities.o \
		 textureManager.o \
		 game.o \
		 levelManager.o



COMPOBJ := $(patsubst %, $(OBJ_PATH)%, $(COMPONENT_OBJS))

OBJ := $(patsubst %,$(OBJ_PATH)%, $(OBJ1))



#build components.o
$(OBJ_PATH)%.o: $(COMPONENTS_SRC)%.c  
				@echo [CC] $<
				@$(CC) $(CFLAGS) -o $@ -c $< $(INC_PATH)

#build .o
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@echo [CC] $<
				@$(CC) $(CFLAGS) -o $@ -c $< $(INC_PATH)


#build final binary
$(TARGET):	 $(OBJ)  $(COMPOBJ)
			@$(CC) -o $@ $^ $(LINKFLAGS)

#clean all files
clean:
		@echo "[Cleaning]"
		-rm $(OBJ_PATH)*o
		@$(RM) -rfv $(TARGET)