### ALUNOS E INSTITUICAO
Projeto realizado referente à disciplina Sistemas Operacionais 1 lecionada, pela docente Kelen Vivaldini, ao curso de Bacharelado em Ciência da Computação na Universidade Federal de São Carlos

#### Alunos:
    André Camargo Rocha            RA: 587052
    Guilherme Lemos                RA: 587010
    João Gabriel Fanhani Marins    RA: 586919
    Miguel Gonçalves Vieira        RA: 609790

### DESCRICAO

mycall.c é uma chamada de sistema que, ao passarmos um caminho, um nome e um conteúdo como parâmetros, ela cria o arquivo com o nome e caminho especificados, abre esse arquivo e escreve o conteúdo passado como parametro. Caso o caminho não exista, o diretório será criado

### IMPLEMENTAÇÃO

  Assumindo que a imagem do linux utilizada esteja na pasta pai de linux-3.17.2 e esteja nomeada como DC_SO.img, temos os seguintes passos a serem realizados:

  1. Alterar o arquivo:
        `linux-3.17.2/arch/x86/syscalls/syscall_32.tlb`, adicionando a linha: `357 i386 mycall sys_mymemset`

  2. Copiar `mycall.c` para o diretório `linux-3.12/arch/x86/kernel/``

  3. Incluir a linha:
	`asmlinkage long createFile(const char fileName[], const char dirPath[], const char toWrite[])` no local adequado do arquivo `linux-3.17.2/include/linux/syscalls.h`

  4. Alterar o arquivo `Makefile` que está no diretório `linux-3.17.2/arch/x86/kernel/`, incluindo uma linha:
	`obj-y += mycall.o`

  5. Copiar o arquivo `ex-mycall.c` para a pasta que está a imagem do linux

  6. Rodar a imagem do linux inserindo o executável de ex-mycall.c:
	 `qemu-system-i386 -hda DC_SO.img -kernel linux-3.17.2/arch/i386/boot/bzImage -append "ro root=/dev/hda" -hdb ex-mycall`

  7. Logar no sistema aberto pelo QEMU com as credenciais corretas

  8. Rodar os comandos: `cat /dev/hdb > ex-mycall && chmod +x ex-mycall && ./ex-mycall pelo QEMU`
