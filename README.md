# Pipex

Pipex는 UNIX 시스템에서 파이프와 프로세스 간 통신을 이해하고 구현하는 프로젝트입니다. 이 프로젝트는 42서울 커리큘럼의 일부로, 파일 입출력, 프로세스 생성 및 관리, 파이프를 통한 데이터 전송 등을 다룹니다.

## 목차
- [개요](#개요)
- [기능](#기능)
- [설치](#설치)
- [사용법](#사용법)


## 개요

Pipex 프로젝트는 두 개의 명령어를 파이프로 연결하여 실행하는 프로그램을 작성하는 것을 목표로 합니다. 이는 `file1`의 내용을 `cmd1`을 통해 처리한 결과를 `cmd2`로 전달하여 `file2`에 저장하는 방식입니다.

### 프로그램 실행 형식
```sh
./pipex file1 cmd1 cmd2 file2

이 프로그램은 file1의 내용을 cmd1을 통해 처리하고, 그 결과를 cmd2로 전달하여 file2에 저장합니다.

**기능**
cmd1과 cmd2는 각각 쉘 명령어로 실행됩니다.
파일 입출력 기능
파이프와 프로세스를 통한 데이터 전송
다양한 시스템 호출을 사용하여 프로세스와 파이프 관리
견고한 에러 핸들링
설치
이 저장소를 클론합니다:

```sh
git clone https://github.com/yourusername/pipex.git
프로젝트 디렉토리로 이동합니다:

```sh
cd pipex
Makefile을 사용하여 프로그램을 컴파일합니다:

```sh
make
사용법
pipex 실행:

```sh
./pipex file1 "cmd1" "cmd2" file2
예시:

```sh
./pipex infile "ls -l" "wc -l" outfile
위 명령어는 infile의 내용을 읽고, ls -l 명령어를 실행하여 그 출력을 wc -l 명령어로 전달한 후, 최종 결과를 outfile에 저장합니다.
