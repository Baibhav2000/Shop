OBJ=connect.o main.o customer.o useful.o order.o display.o bill.o
TARGET=out

all:$(OBJ) $(TARGET)

%.o:%.cpp
	@g++ -c -fPIC $< -L/usr/include/mysql -lmysqlclient -I/usr/include/mysql
	@echo "Compiling $<"
	
$(TARGET):$(OBJ)
	@g++ -o $(TARGET) $(OBJ) -L/usr/include/mysql -lmysqlclient -I/usr/include/mysql

clean:
	@rm -rf $(TARGET) $(OBJ)
run:
	@./$(TARGET)
