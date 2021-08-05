/*
Escreva uma função que receba dois registros do tipo data, cada um representando uma data válida, e devolva o
número de dias que decorreram entre as duas datas.
Mateus Vespasiano de Castro
*/

#include <stdio.h> 
#include <stdbool.h> 

struct dma { 
    int dia; 
    int mes; 
    int ano; 
}; 

bool valida(struct dma data) { 
    if (data.mes < 1 || data.mes > 12) 
        return false; 
    else {
        if (data.mes == 2) {
            if (((data.ano % 4 == 0) && (data.ano % 100 != 0)) || (data.ano % 400 == 0)) { 
                if (data.dia < 1 || data.dia > 29) 
                    return false; 
                } 
            else 
                if (data.dia < 1 || data.dia > 28) 
                    return false; 
                } 
        else {
            if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) {
                if (data.dia < 1 || data.dia > 30) 
                    return false; 
                } 
            else 
                if (data.dia < 1 || data.dia > 31) 
                return false; 
            } 
        }    
        return true; 
    } 

    int dias_decorridos(struct dma data_ini, struct dma data_fim) { 
        float dias_no_mes[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, tot_dias_ini, tot_dias_fim;
        int i;

        tot_dias_ini = data_ini.ano * 365.2425;

        for (i=1; i<data_ini.mes; i++){
            tot_dias_ini += dias_no_mes[i]; 
            if ((((data_ini.ano % 4 == 0) && (data_ini.ano % 100 != 0)) || (data_ini.ano % 400 == 0)) && data_ini.mes > 2)
                tot_dias_ini++; 
            tot_dias_ini += data_ini.dia; 
        }

        tot_dias_fim = data_fim.ano * 365.2425; 

        for (i=1; i<data_fim.mes; i++) 
            tot_dias_fim += dias_no_mes[i]; 
            if (((data_fim.ano % 4 == 0) && (data_fim.ano % 100 != 0) || (data_fim.ano % 400 == 0)) && data_fim.mes > 2) 
                tot_dias_fim++; 
            tot_dias_fim += data_fim.dia; 

    return (tot_dias_fim - tot_dias_ini); 
} 