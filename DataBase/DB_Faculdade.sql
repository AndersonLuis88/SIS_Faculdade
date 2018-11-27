--
-- File generated with SQLiteStudio v3.2.1 on dom nov 18 14:50:00 2018
--
-- Text encoding used: System
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: disciplina
CREATE TABLE disciplina (id_disciplina INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE, nome VARCHAR (40) NOT NULL, professor BIGINT REFERENCES pessoa (id_cpf), Fase INT);
INSERT INTO disciplina (id_disciplina, nome, professor, Fase) VALUES (1, 'Algoritmo', 10000000001, 1);
INSERT INTO disciplina (id_disciplina, nome, professor, Fase) VALUES (2, 'Algoritmo II', 20000000002, 2);
INSERT INTO disciplina (id_disciplina, nome, professor, Fase) VALUES (3, 'Arquitetura de Computadores', 10000000001, 1);
INSERT INTO disciplina (id_disciplina, nome, professor, Fase) VALUES (4, 'CIrcuitos Lógicos', 20000000002, 2);

-- Table: notas
CREATE TABLE notas (id_cpf BIGINT REFERENCES pessoa (id_cpf), Nota1 DOUBLE, Nota2 DOUBLE, Nota3 DOUBLE, disciplina VARCHAR (40));
INSERT INTO notas (id_cpf, Nota1, Nota2, Nota3, disciplina) VALUES (30000000003, 8.0, 6.0, 9.0, 'Algoritmo');

-- Table: pessoa
CREATE TABLE pessoa (id_cpf BIGINT PRIMARY KEY NOT NULL, nome VARCHAR (40) NOT NULL UNIQUE, cnpj INTEGER UNIQUE, acesso INT NOT NULL, senha INT UNIQUE);
INSERT INTO pessoa (id_cpf, nome, cnpj, acesso, senha) VALUES (10000000001, 'pessoa1', 1111, 0, 123);
INSERT INTO pessoa (id_cpf, nome, cnpj, acesso, senha) VALUES (20000000002, 'pessoa2', 2222, 0, 456);
INSERT INTO pessoa (id_cpf, nome, cnpj, acesso, senha) VALUES (30000000003, 'pessoa3', 3333, 1, 789);
INSERT INTO pessoa (id_cpf, nome, cnpj, acesso, senha) VALUES (40000000004, 'pessoa4', 4444, 1, 111);

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
