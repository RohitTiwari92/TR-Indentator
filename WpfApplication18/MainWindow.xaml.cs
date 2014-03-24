using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Win32;
using System.IO;
using System.Diagnostics;
namespace WpfApplication18
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        string s;
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Rectangle_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            this.DragMove();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            this.WindowState = System.Windows.WindowState.Minimized;
        }



        private void TBox_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effects = DragDropEffects.Move;
            }
            else
            {
                e.Effects = DragDropEffects.None;
            }

        }

        private void TBox_Drop(object sender, DragEventArgs e)
        {           
            try
            {
                Array a = (Array)e.Data.GetData(DataFormats.FileDrop);
                if (a != null)
                {
                     s = a.GetValue(0).ToString();
                    LoadFile();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error in DragDrop function: " + ex.Message);
            }
        }
        private void w1_Closed(object sender,  EventArgs e)
        {
            this.IsEnabled = true;
            TBox.Text = String.Empty;
            BTB.Visibility = Visibility.Visible;
            B1.Visibility = Visibility.Visible;
            //MessageBox.Show("hello");
        }
        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            //filteration of files
            //browse button 
           
            dlg.Filter = "(*.c;*.cpp;*.java;*.cs;)|*.c;*.cpp;*.java;*.cs|" + "All files (*.*)|*.*";
            
            Nullable<bool> result = dlg.ShowDialog();
           
            if (result == true)
            {
                 
                s = dlg.FileName;
                LoadFile();
            }
        }
        private void LoadFile()
        {
            BTB.Visibility = Visibility.Collapsed;
            B1.Visibility = Visibility.Collapsed;
            //drag and browes file extation check
            if (System.IO.Path.GetExtension(s).Equals(".c", StringComparison.InvariantCultureIgnoreCase) || System.IO.Path.GetExtension(s).Equals(".cpp", StringComparison.InvariantCultureIgnoreCase) || System.IO.Path.GetExtension(s).Equals(".java", StringComparison.InvariantCultureIgnoreCase) || System.IO.Path.GetExtension(s).Equals(".cs", StringComparison.InvariantCultureIgnoreCase))
            {
                //load into textblock
                using (TextReader tr = new StreamReader(s))
                {
                    string gg = tr.ReadToEnd();
                    TBox.Text = gg;
                }
            }
            else
            {
                this.IsEnabled = false;
                Window1 w1 = new Window1("Enter Correct File Format");
                w1.Closed += new EventHandler(w1_Closed);
                w1.Topmost = true;
                w1.Show();
            }
        }

        void indent()
        {
            //c program exe execute for indention 
            ProcessStartInfo psi = new ProcessStartInfo();
            psi.CreateNoWindow = true;
            psi.UseShellExecute = false;
            psi.FileName = "main.exe";
            psi.WindowStyle = ProcessWindowStyle.Hidden;
            //pass argument
            psi.Arguments = s;
            try
            {
           
                using (Process exeProcess = Process.Start(psi))
                {
                    exeProcess.WaitForExit();
                }
            }
            catch (Exception e)
            {
                MessageBox.Show("error in process : " + e.ToString()); 
            }

        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            save();
            

        }
        void save()
        {
            //run (write back (wb)) exe 
            ProcessStartInfo psi = new ProcessStartInfo();
            psi.CreateNoWindow = true;
            psi.UseShellExecute = false;
            psi.FileName = "wb.exe";
            psi.WindowStyle = ProcessWindowStyle.Hidden;
            psi.Arguments = s;
            try
            {

                using (Process exeProcess = Process.Start(psi))
                {
                    exeProcess.WaitForExit();
                }
            }
            catch (Exception e)
            {
                MessageBox.Show("error in process : " + e.ToString());
            }
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            indent();
            showtxt();
        }
        void showtxt()
        {
            ProcessStartInfo psi = new ProcessStartInfo();
            psi.CreateNoWindow = true;
            psi.UseShellExecute = false;
            //the wbt file is updatetion of wb file which recive the text from temp file and write in temp4 file 
            psi.FileName = "wbt.exe";
            psi.WindowStyle = ProcessWindowStyle.Hidden;
            psi.Arguments = s;
            try
            {

                using (Process exeProcess = Process.Start(psi))
                {
                    exeProcess.WaitForExit();
                }
            }
            catch (Exception e)
            {
                MessageBox.Show("error in process : " + e.ToString());
            }
            
            using (TextReader tr = new StreamReader("temp4.txt"))
            {
                string gg = tr.ReadToEnd();
                TBox.Text = gg;
            }
       }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            //save as button
            //save as dialog box
            SaveFileDialog sfd = new SaveFileDialog();
            Nullable<bool> result = sfd.ShowDialog();
            if (result == true)
            {
                // Open document 
                string s1 = sfd.FileName;
                saveas(s1);
            }




        }
        void saveas(string s1)
        {
            //save as function
            ProcessStartInfo psi = new ProcessStartInfo();
            psi.CreateNoWindow = false;
            psi.UseShellExecute = false;
            psi.FileName = "wb.exe";
            psi.WindowStyle = ProcessWindowStyle.Hidden;
            psi.Arguments = s1;
            try
            {

                using (Process exeProcess = Process.Start(psi))
                {
                    exeProcess.WaitForExit();
                }
            }
            catch (Exception e)
            {
                MessageBox.Show("error in process : " + e.ToString());
            }
        }
        



    }
}
