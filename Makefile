CC      = gcc
CFLAGS  = -g -Wall -O2
LDFLAGS = -lGL -lglut
LIBS    =
INCLUDE =
SRC_DIR = ./src
OBJ_DIR = ./build

all: alpha animation basic-2D basic-3D draw-cube list material mouse-key polygon

alpha:
	@if [ ! -d $(OBJ_DIR) ]; \
		then echo "mkdir -p $(OBJ_DIR)"; mkdir -p $(OBJ_DIR); \
	fi
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_DIR)/$@.c -o $(OBJ_DIR)/$@ $(LDFLAGS)

animation:
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_DIR)/$@.c -o $(OBJ_DIR)/$@ $(LDFLAGS)

basic-2D:
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_DIR)/$@.c -o $(OBJ_DIR)/$@ $(LDFLAGS)

basic-3D:
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_DIR)/$@.c -o $(OBJ_DIR)/$@ $(LDFLAGS)

draw-cube:
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_DIR)/$@.c -o $(OBJ_DIR)/$@ $(LDFLAGS)

list:
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_DIR)/$@.c -o $(OBJ_DIR)/$@ $(LDFLAGS)

material:
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_DIR)/$@.c -o $(OBJ_DIR)/$@ $(LDFLAGS)

mouse-key:
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_DIR)/$@.c -o $(OBJ_DIR)/$@ $(LDFLAGS)

polygon:
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC_DIR)/$@.c -o $(OBJ_DIR)/$@ $(LDFLAGS)

clean:
	echo "Removing build artifacts..."
	rm -rf $(OBJ_DIR)