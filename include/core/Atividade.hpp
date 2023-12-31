#pragma once
#include <string>
#include <vector>
#include "Horario.hpp"
namespace task_manager::core{

enum TIPO_HORARIO{FIXO, LIVRE};

enum TURNO_PREFERENCIA{MANHA, TARDE, NOITE, NENHUM};

enum DIA{DOM, SEG, TER, QUA, QUI, SEX, SAB};

///@brief Classe feita para representar uma Atividade, que pode ter um horário fixo ou livre. Dependendo de qual o construtor usado será diferente.

class Atividade{
    public:

    /// @brief construtor Atividade com horário livre
    /// @param nome 
    /// @param tipo_horario 
    /// @param turno_preferencia 
    /// @param duracao_minutos 
    /// @param dias_semana 
    Atividade(std::string nome, TIPO_HORARIO tipo_horario, TURNO_PREFERENCIA turno_preferencia, 
    unsigned duracao_minutos, std::vector<DIA> dias_semana);
    
    /// @brief construtor Atividade com horário fixo
    /// @param nome 
    /// @param tipo_horario 
    /// @param inicio 
    /// @param fim 
    /// @param dias_semana 
    Atividade(std::string nome, TIPO_HORARIO tipo_horario, 
    Horario inicio, Horario fim, std::vector<DIA> dias_semana);
    
    /// @brief implementação comparação entre atividades
    /// @param other 
    /// @return Verdadeiro ou falso.
    bool operator==(const Atividade& other) const;
    
    /// @brief recupera o nome da atividade (_nome)
    /// @return String com o valor de _nome.
    std::string get_nome() const;
    
    /// @brief recupera o horário da atividade (_horario)
    /// @return Retorna _horario.
    TIPO_HORARIO get_tipo_horario() const;
    
    /// @brief recupera a duração atividade (_horario)
    /// @return Retorna a duração _horario.
    unsigned get_duracao() const;
    
    /// @brief recupera o dia da atividade a ser checada (_dia_semana)
    /// @return Vetor de dias com dias da semana. 
    std::vector<DIA> get_dias_semana() const;
    
    /// @brief recupera o turno de preferencia da atividade (_turno_preferencia)  
    /// @return Retorna o turno de preferência.
    TURNO_PREFERENCIA get_turno() const;
    
    /// @brief - recupera o horário de inicio da atividade
    /// @return objeto do tipo Horario.
    Horario get_horario_inicio() const;
    
    /// @brief - recupera o horário de termino da atividade
    /// @return objeto do tipo Horario.
    Horario get_horario_fim() const;
    
    /// @brief - set o novo horário de inicio
    void set_horario_inicio(Horario inicio);
    
    /// @brief - set o novo horário de fim
    void set_horario_fim(Horario fim);
    
    /// @brief Devolve o objeto em formato de string
    /// @return Retorna uma string formatada do objeto.
    std::string to_string() const;
    
    /// @brief - organiza o vetor de dias da semana
    /// @param dias - vetor a ser organizado
    static void sort_dia(std::vector<DIA>& dias);
    
    /// @brief compara atividades diferentes conforme a sua ordem (dia e turno) 
    /// @param a 
    /// @param b 
    /// @return Verdadeiro ou falso.
    static bool comparar_atividades(const Atividade& a, const Atividade& b);
    
    /// @brief retorna o horario com base no input do usuario
    /// @return Objeto Atividade.
    static Atividade criarAtividade();

    /// @brief - retorna o dia da semana com base no indice
    /// @param indice - indice do dia
    static void dia_corresp(int indice);
    
    private:
        std::string _nome;
        TIPO_HORARIO _tipo_horario; 
        Horario _horario_inicio;
        Horario _horario_fim;
        TURNO_PREFERENCIA _turno_preferencia; 
        unsigned _duracao;
        std::vector<DIA> _dias_semana; 
};

}