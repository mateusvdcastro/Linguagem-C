import os
import pandas as pd
from tkinter import Tk, Label, Button, filedialog, messagebox, Grid
from fpdf import FPDF
from PIL import Image

# Inicializando variáveis globais
caminho_xlsx = None
caminho_destino = None
caminho_template = None

def validar_entrada():
    """Habilita o botão de gerar certificados se todas as entradas estiverem preenchidas."""
    if caminho_xlsx and caminho_destino and caminho_template:
        btn_gerar_certificados.config(state="normal")
    else:
        btn_gerar_certificados.config(state="disabled")

def selecionar_arquivo():
    """Abre o dialog para selecionar o arquivo Excel."""
    global caminho_xlsx
    caminho_xlsx = filedialog.askopenfilename(
        title="Selecione o arquivo .xlsx",
        filetypes=[('Arquivo Excel', '*.xlsx')]
    )
    if caminho_xlsx:
        lbl_arquivo.config(text=f"Arquivo: {os.path.basename(caminho_xlsx)}")
        validar_entrada()

def selecionar_diretorio():
    """Abre o dialog para selecionar o diretório de destino."""
    global caminho_destino
    caminho_destino = filedialog.askdirectory(title="Selecione o diretório de destino")
    if caminho_destino:
        lbl_diretorio.config(text=f"Diretório: {caminho_destino}")
        validar_entrada()

def selecionar_template():
    """Abre o dialog para selecionar o template PNG."""
    global caminho_template
    caminho_template = filedialog.askopenfilename(
        title="Selecione o template .png",
        filetypes=[('Arquivo PNG', '*.png')]
    )
    if caminho_template:
        lbl_template.config(text=f"Template: {os.path.basename(caminho_template)}")
        validar_entrada()

def gerar_certificados():
    """Gera certificados baseados no Excel e no template fornecidos."""
    try:
        # Ler o arquivo Excel
        df = pd.read_excel(caminho_xlsx)

        # Verificar se as colunas necessárias estão presentes
        colunas_necessarias = ['Nome do Aluno', 'Data de Início', 'Data de Fim', 'Horas de curso', 'Nome do Curso']
        for coluna in colunas_necessarias:
            if coluna not in df.columns:
                messagebox.showerror("Erro", f"Coluna '{coluna}' não encontrada no arquivo.")
                return

        # Carregar o template
        template_image = Image.open(caminho_template)
        template_width, template_height = template_image.size

        # Gerar certificados para cada linha do DataFrame
        for index, row in df.iterrows():
            nome = row['Nome do Aluno']
            curso = row['Nome do Curso']
            data_inicio = row['Data de Início']
            data_fim = row['Data de Fim']
            horas = row['Horas de curso']

            pdf = FPDF(unit="pt", format=[template_width, template_height])
            pdf.add_page()
            pdf.image(caminho_template, x=0, y=0, w=template_width, h=template_height)
            pdf.set_font("Arial", size=16)  # Ajustar o tamanho da fonte para 16 pt
            pdf.set_text_color(0, 0, 0)  # Texto preto

            # Ajustar a posição para centralizar o texto
            margem_esquerda = 50
            altura_texto = 400  # Ajuste fino da altura vertical do texto

            pdf.set_xy(margem_esquerda, altura_texto)
            texto = (
                f"Certificamos que {nome} concluiu o curso {curso} "
                f"com carga horária de {horas} horas, realizado entre {data_inicio} e {data_fim}."
            )
            pdf.multi_cell(template_width - 100, 30, texto, align='C')  # Centralizando o texto

            # Salvar o PDF no caminho de destino
            caminho_pdf = os.path.join(caminho_destino, f"Certificado_{nome}.pdf")
            pdf.output(caminho_pdf)

        messagebox.showinfo("Sucesso", "Certificados gerados com sucesso!")
    except Exception as e:
        messagebox.showerror("Erro", f"Ocorreu um erro: {e}")

if __name__ == '__main__':
    # Inicializar a interface gráfica
    root = Tk()
    root.title('CertGenerator - Gerador de Certificados')
    root.geometry('720x480')

    # Layout usando grid para melhor organização
    Grid.rowconfigure(root, [0, 1, 2, 3, 4, 5], weight=1)
    Grid.columnconfigure(root, [0, 1], weight=1)

    Label(root, text='Selecione o arquivo .xlsx:').grid(row=0, column=0, sticky='e')
    btn_selecionar_arquivo = Button(root, text="Selecionar", command=selecionar_arquivo)
    btn_selecionar_arquivo.grid(row=0, column=1, padx=5, pady=5)

    lbl_arquivo = Label(root, text="Nenhum arquivo selecionado")
    lbl_arquivo.grid(row=1, column=0, columnspan=2)

    Label(root, text='Selecione o diretório de destino:').grid(row=2, column=0, sticky='e')
    btn_selecionar_diretorio = Button(root, text="Selecionar", command=selecionar_diretorio)
    btn_selecionar_diretorio.grid(row=2, column=1, padx=5, pady=5)

    lbl_diretorio = Label(root, text="Nenhum diretório selecionado")
    lbl_diretorio.grid(row=3, column=0, columnspan=2)

    Label(root, text='Selecione o template .png:').grid(row=4, column=0, sticky='e')
    btn_selecionar_template = Button(root, text="Selecionar", command=selecionar_template)
    btn_selecionar_template.grid(row=4, column=1, padx=5, pady=5)

    lbl_template = Label(root, text="Nenhum template selecionado")
    lbl_template.grid(row=5, column=0, columnspan=2)

    # Botão para gerar os certificados
    btn_gerar_certificados = Button(root, text="Gerar Certificados", command=gerar_certificados, state="disabled")
    btn_gerar_certificados.grid(row=6, column=0, columnspan=2, pady=20)

    root.mainloop()
