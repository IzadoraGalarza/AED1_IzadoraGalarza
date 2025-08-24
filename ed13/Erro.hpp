/**
 * Classe para tratar erro.
 */

 #ifndef _ERRO_H_
 #define _ERRO_H_

 class Erro
 {
    /** tartamento de erro.
     * Codigo de erro;
     * 0. Nao ha erro
     */

     private: 
     int erro;

     protected:

     // --------------------------- metodos para acesso restrito

     /**
      * Metodo para estabelecer novo codigo de erro
      * @param codigo de erro a ser guardado
      */

      void setErro (int codigo)
      {
        erro = codigo;
      }

      /** 
       * definicoes publicas
      */

      public: 
      /**
       * Destrutor
       */
      ~Erro ()
      {}

      /**
       * construtor padrao
       */

       Erro()
       {
        //atribuir valor inicial
        erro =0;
       }

       //-----------------------------------metodos para acesso

       int getErro()
       {
        return(erro);
       }
       
    };
 #endif