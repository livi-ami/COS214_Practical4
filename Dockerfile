FROM ubuntu:latest

RUN apt-get update && apt-get install -y build-essential

WORKDIR /taskforgeApp

COPY src/ .

RUN g++ -std=c++11 -static \ 
    -I. \ 
    -I./vehicle \
    -I./iterator \
    -I./transport \
    -o taskforge $(find . -name "*.cpp") 

CMD ["./taskforge"]