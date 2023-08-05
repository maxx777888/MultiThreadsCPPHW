FROM ubuntu:16.04
LABEL mantainer="homeworkMT@mail.ru"
RUN apt-get update && apt-get install -y g++ nano 
WORKDIR /root/test/
COPY hello_world.cpp .
RUN g++ hello_world.cpp -o hello_world
CMD ["./hello_world"]