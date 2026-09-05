FROM ubuntu:24.04 AS build

RUN apt-get update && apt-get install -y build-essential

WORKDIR /app

COPY hello/ .

RUN g++ -o hello hello.cpp -static

CMD ["./hello"]