"""
Crie um programa executável em python, que abra uma interface gráfica, que recebe um diretório como 
input do local em que um arquivo .xlsx está armazenado, e é capaz de acessar essa base de dados e 
executar buscar nas colunas [Nome do Aluno, Data de Início, Data de Fim, Horas de curso, Nome do Curso] 
e emitir certificados em .PDF automaticamente. A interface gráfica também deve perguntar o diretório 
destino em que o usuário gostaria de salvar os PDFs.
"""

import os
import pandas as pd
from tkinter import Tk, Label, Button, filedialog, messagebox
from fpdf import FPDF
from PIL import Image

def selecionar_arquivo():
    global caminho_xlsx
    caminho_xlsx = filedialog.askopenfilename(title="Selecione o arquivo .xlsx", filetypes=[('Arquivo Excel', '*.xlsx')])
    if caminho_xlsx:
        lbl_arquivo.config(text=f"Arquivo Selecionado: {caminho_xlsx}")
        btn_gerar_certificados.config(state="normal")
    return caminho_xlsx

def selecionar_diretorio():
    global caminho_destino
    caminho_destino = filedialog.askdirectory(title="Selecione o diretório de destino")
    if caminho_destino:
        lbl_diretorio.config(text=f"Diretório Selecionado: {caminho_destino}")
        return caminho_destino
    

def iniciar_interface():
    print('Iniciar Interface')
    if caminho_xlsx and caminho_destino:
        print(caminho_xlsx, caminho_destino)
        gerar_certificados(caminho_xlsx, caminho_destino, caminho_template)

def gerar_certificados(caminho_xlsx, caminho_destino, caminho_template=None):
    try:
        # Ler o arquivo Excel
        df = pd.read_excel(caminho_xlsx)

        print(df.head())
        print(caminho_xlsx)
        print(caminho_destino)

        # Gerar certificados
        # Verificar se as colunas necessárias estão presentes
        colunas_necessarias = ['Nome do Aluno', 'Data de Início', 'Data de Fim', 'Horas de curso', 'Nome do Curso']
        for coluna in colunas_necessarias:
            if coluna not in df.columns:
                messagebox.showerror("Erro", f"Coluna '{coluna}' não encontrada no arquivo.")
                return
            
        # Carregar o template
        if caminho_template:
            template_image = Image.open(caminho_template)
            template_width, template_height = template_image.size
            
        # Gerar certificados
        for index, row in df.iterrows():
            nome = row['Nome do Aluno']
            matricula = row['Matrícula']
            curso = row['Nome do Curso']
            data_inicio = row['Data de Início']
            data_fim = row['Data de Fim']
            horas = row['Horas de curso']

            pdf = FPDF(unit="pt", format=[template_width, template_height])

            # Criar página com o template
            pdf.add_page()
            pdf.image(caminho_template, x=0, y=0, w=template_width, h=template_height) # x é a margem esquerda, y é a margem superior, w é a largura, h é a altura
            pdf.set_font("Arial", size=12)
            pdf.set_text_color(0, 0, 0) # RGB

            # pdf.cell(200, 10, txt="Certificado de Conclusão", ln=True, align='C')
            # pdf.ln(10)

            pdf.set_xy(2, 2) # x é a margem esquerda, y é a margem superior 
            texto = (f"Certificamos que o(a) aluno(a) {nome}, matrícula {matricula},  participou da Liga Acadêmica de "
                     f"Medicina Legal, da Universidade Estácio de Sá - Campus Città, na condição de Secretária, durante o período de {data_inicio} e {data_fim}.")
            pdf.multi_cell(0, 30, texto)

            # Salvar o certificado no caminho de destino
            caminho_pdf = os.path.join(caminho_destino, f"Certificado_{nome}.pdf")
            pdf.output(caminho_pdf)
    except Exception as e:
        messagebox.showerror("Erro", f"Erro ao ler o arquivo Excel: {e}")
        return
    
def selecionar_template():
    global caminho_template
    caminho_template = filedialog.askopenfilename(title="Selecione o template .png", filetypes=[('Arquivo PNG', '*.png')])
    if caminho_template:
        lbl_template.config(text=f"Template Selecionado: {caminho_template}")
    return caminho_template

if __name__ == '__main__':
    print('CertGenerator')
    # Interface gráfica
    root = Tk()
    root.title('CertGenerator')
    root.geometry('720x480')

    Label(root, text='Selecione o arquivo .xlsx:').pack()

    btn_selecionar_arquivo = Button(root, text="Selecionar arquivo .xlsx", command=selecionar_arquivo)
    btn_selecionar_arquivo.pack(pady=5)

    lbl_arquivo = Label(root, text="Nenhum arquivo selecionado")
    lbl_arquivo.pack()

    # Botão para selecionar o diretório de destino
    btn_selecionar_diretorio = Button(root, text="Selecionar diretório destino", command=selecionar_diretorio)
    btn_selecionar_diretorio.pack(pady=5)

    # Label para exibir o diretório selecionado
    lbl_diretorio = Label(root, text="Nenhum diretório selecionado")
    lbl_diretorio.pack()

    # Botão para selecionar o template .png
    btn_selecionar_template = Button(root, text="Selecionar template .png", command=selecionar_template)
    btn_selecionar_template.pack(pady=5)

    # Label para exibir o template selecionado
    lbl_template = Label(root, text="Nenhum template selecionado")
    lbl_template.pack()

    # Botão para gerar certificados
    btn_gerar_certificados = Button(root, text="Gerar Certificados", command=iniciar_interface, state="disabled")
    btn_gerar_certificados.pack(pady=20)

    root.mainloop()

