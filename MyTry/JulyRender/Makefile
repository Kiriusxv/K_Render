# 定义编译器
CXX = g++

# 定义编译选项
CXXFLAGS = -ggdb -g -pg -O0 -Wall -std=c++11

# 定义目标文件
TARGET = main

# 定义源文件
SRCS = main.cpp tgaimage.cpp

# 定义对象文件
OBJS = $(SRCS:.cpp=.o)

# 链接生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 生成对象文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 运行 gprof 分析
.PHONY: profile
profile: $(TARGET)
	./$(TARGET)
	gprof $(TARGET) gmon.out > analysis.txt
	cat analysis.txt

# 清理生成的文件
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) gmon.out analysis.txt