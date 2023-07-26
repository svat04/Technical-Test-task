CC = g++
CFLAGS = -Wall -Wextra

LIB_SRC = file_search_lib.cpp
LIB_OBJ = $(LIB_SRC:.cpp=.o)
LIB_NAME = libfilesearch.a

APP_SRC = main.cpp
APP_OBJ = $(APP_SRC:.cpp=.o)
APP_NAME = file_search_app.exe

all: $(LIB_NAME) $(APP_NAME)

$(LIB_NAME): $(LIB_OBJ)
	ar rcs $(LIB_NAME) $(LIB_OBJ)

$(APP_NAME): $(APP_OBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $(APP_NAME) $(APP_OBJ) -L. -lfilesearch

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del $(LIB_NAME) $(APP_NAME) $(LIB_OBJ) $(APP_OBJ)
