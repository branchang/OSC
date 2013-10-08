package lntool;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

import java.awt.GridLayout;

import javax.swing.JTextArea;
import javax.swing.JLabel;

import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;

import javax.swing.JCheckBoxMenuItem;
import javax.swing.JDialog;
import javax.swing.JFileChooser;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JSeparator;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MainWindow implements ActionListener{

	private JFrame frame;
	private JTextField textField_0;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	private JTextField textField_4;
	private File filename;
	
	String arrPara[] = {"home_page", "stbid", "mac", "ntvuseraccount", "ntvuserpassword"};

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainWindow window = new MainWindow();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public MainWindow() {
		
		initialize();
	}

	private void uimanager_init(String windows)
	{
		try {
			UIManager.setLookAndFeel(windows);
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedLookAndFeelException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 600, 412);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//windows风格初始化
		uimanager_init("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
		
		JPanel panel_1 = new JPanel();
		frame.getContentPane().add(panel_1, BorderLayout.CENTER);
		panel_1.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("主页地址:");
		lblNewLabel.setFont(new Font("Dialog", Font.BOLD, 13));
		lblNewLabel.setBounds(35, 24, 88, 30);
		panel_1.add(lblNewLabel);
		
		textField_0 = new JTextField();
		textField_0.setEditable(false);
		textField_0.setBounds(141, 25, 401, 30);
		panel_1.add(textField_0);
		textField_0.setColumns(10);
		
		JLabel label = new JLabel("STBID:");
		label.setFont(new Font("Dialog", Font.BOLD, 13));
		label.setBounds(35, 76, 88, 30);
		panel_1.add(label);
		
		textField_1 = new JTextField();
		textField_1.setEditable(false);
		textField_1.setColumns(10);
		textField_1.setBounds(141, 75, 401, 30);
		panel_1.add(textField_1);
		
		JLabel label_1 = new JLabel("升级地址:");
		label_1.setBounds(35, 125, 88, 30);
		panel_1.add(label_1);
		
		textField_2 = new JTextField();
		textField_2.setEditable(false);
		textField_2.setColumns(10);
		textField_2.setBounds(141, 125, 401, 30);
		panel_1.add(textField_2);
		
		JLabel label_2 = new JLabel("用户帐号:");
		label_2.setBounds(35, 175, 88, 30);
		panel_1.add(label_2);
		
		textField_3 = new JTextField();
		textField_3.setColumns(10);
		textField_3.setBounds(141, 175, 401, 30);
		panel_1.add(textField_3);
		
		JLabel label_3 = new JLabel("用户密码:");
		label_3.setBounds(35, 225, 88, 30);
		panel_1.add(label_3);
		
		textField_4 = new JTextField();
		textField_4.setColumns(10);
		textField_4.setBounds(141, 225, 401, 30);
		panel_1.add(textField_4);
		
		JPanel panel = new JPanel();
		panel.setBounds(0, 302, 554, 35);
		panel_1.add(panel);
		panel.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 5));
		
		JButton btnOpenFile = new JButton("打开文件");
		btnOpenFile.addActionListener(this);
		btnOpenFile.setActionCommand("OpenFile");
		panel.add(btnOpenFile);
		
		//同菜单种的保存按钮
		JButton btnSaveFile = new JButton("保存文件");
		btnSaveFile.setActionCommand("Save");
		btnSaveFile.addActionListener(this);
		panel.add(btnSaveFile);
		
		JMenuBar menuBar = new JMenuBar();
		frame.setJMenuBar(menuBar);
		
		JMenu mnFile = new JMenu("文件");
		menuBar.add(mnFile);
		//
		JCheckBoxMenuItem item1 = new JCheckBoxMenuItem("跑步");
		mnFile.add(item1);
		
		//
		JMenuItem mntmFileOpen = new JMenuItem("打开文件...");
		mntmFileOpen.addActionListener(this);
		mntmFileOpen.setActionCommand("OpenFile");
		mnFile.add(mntmFileOpen);
		
		JMenuItem mntmSaveAs = new JMenuItem("另存为");
		mntmSaveAs.setActionCommand("SaveAs");
		mntmSaveAs.addActionListener(this);
		mnFile.add(mntmSaveAs);
		
		JMenuItem mntmSave = new JMenuItem("保存");
		mntmSave.setActionCommand("Save");
		mntmSave.addActionListener(this);
		mnFile.add(mntmSave);
		
		JSeparator separator = new JSeparator();
		mnFile.add(separator);
		
		JMenuItem mntmQuit = new JMenuItem("退出");
		mntmQuit.setActionCommand("Quit");
		mntmQuit.addActionListener(this);
		mnFile.add(mntmQuit);
		
		JMenu mnHelp = new JMenu("帮助");
		menuBar.add(mnHelp);
		
		JMenuItem mntmAbout = new JMenuItem("关于");
		mnHelp.add(mntmAbout);
	}
	
	public int parsefile(StringBuffer strBF, String para, StringBuffer value){
		int start = -1;
		int end = -1;
		char str[] = new char[1024];
		value.setLength(0);
		System.out.printf("para:[%s]\n", para);
		start = strBF.indexOf(para);
		if(start>=0)
		{
			start=strBF.indexOf("=", start);
			System.out.printf("start %d \n", start);
		}
		if(start>=0)
		{
			end =strBF.indexOf("\n", start);
		}
	
		if(end>0 && start>=0)
		{
			System.out.printf("end %d \n", end);
			strBF.getChars(start+1, end, str, 0);
		}

		value.append(str);
		System.out.printf("4 %s\n", value);
		return 0;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getActionCommand().equals("OpenFile"))
		{
			//读取文件内容
			JFileChooser c = new JFileChooser();
			int rVal = c.showOpenDialog(frame);
			if(rVal == JFileChooser.APPROVE_OPTION){
				//textField_0.setText(c.getSelectedFile().getAbsolutePath());
				//textField_2.setText(c.getCurrentDirectory().toString());
				filename = c.getSelectedFile();
				StringBuffer strBF = new StringBuffer();
				FileInputStream inputfile = null;
				try {
					char buffer[] = new char[1024];
					inputfile = new FileInputStream(filename);
					FileReader in = new FileReader(filename.getAbsoluteFile());
					int len = 0;
					while ((len = in.read(buffer)) != -1) {
						strBF.append(buffer, 0, len);
					}
					inputfile.close();
					//System.out.print(strBF.toString());
					//解析文件
					StringBuffer value = new StringBuffer();
				//	for(int i=0;i<5;i++)
					//{
					parsefile(strBF,"home_page",value);
					textField_0.setText(value.toString().trim());
					//}
					parsefile(strBF, "stbid", value);
					textField_1.setText(value.toString().trim());
					
					parsefile(strBF, "hw_upgrade_server", value);
					textField_2.setText(value.toString().trim());
					
					parsefile(strBF, "ntvuseraccount", value);
					textField_3.setText(value.toString().trim());
					
					parsefile(strBF, "ntvuserpassword", value);
					textField_4.setText(value.toString().trim());
				
					//System.out.printf("1111111111111%s", value.toString());
					//设置文件显示
				} catch (FileNotFoundException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			
		}else if(e.getActionCommand().equals("SaveAs"))
		{
			//只保存用户名和密码
			JFileChooser c = new JFileChooser();
			int rVal = c.showSaveDialog(frame);
			if(rVal == JFileChooser.APPROVE_OPTION)
			{
				String str;
				File saveFile = c.getSelectedFile();
				StringBuffer strBF = new StringBuffer();
				System.out.print(c.getSelectedFile().getAbsolutePath());
				try {
					FileReader in = new FileReader(filename.getAbsoluteFile());
					BufferedReader bufin = new BufferedReader(in);
					while ((str = bufin.readLine()) != null) {
						String s1 = (String) str.substring(0, 7);
						if(s1!=null &&(s1.compareToIgnoreCase("ntvuser") != 0))
						//if(.compareToIgnoreCase("ntvuseraccount") != 0 && str.substring(0, 14).compareToIgnoreCase("ntvuserpassword") != 0)
						{
							System.out.printf("#### %s####\n", str);
							strBF.append(str);
							strBF.append("\r\n");
						}
					}
					bufin.close();
					
					String sNtvuseraccount = "ntvuseraccount="+textField_3.getText().trim()+"\r\n";
					String sNtvuserpassword = "ntvuserpassword=" + textField_4.getText().trim()+"\r\n";
					strBF.append(sNtvuseraccount);
					strBF.append(sNtvuserpassword);
					System.out.printf("[%s]\n%s \n%s ", strBF.toString(), sNtvuseraccount, sNtvuserpassword);
					BufferedWriter bufwrite = new BufferedWriter(new FileWriter(c.getSelectedFile().getAbsoluteFile()));
					bufwrite.write(strBF.toString());
					bufwrite.flush();
					bufwrite.close();
				} catch (FileNotFoundException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			
			}		
		}else if(e.getActionCommand().equals("Save"))
		{
			//只保存用户名和密码
			char buffer[] = new char[1024];
			FileInputStream inputfile = null;
			String str;
			StringBuffer strBF = new StringBuffer();
			try {
				inputfile = new FileInputStream(filename);
				FileReader in = new FileReader(filename.getAbsoluteFile());
				BufferedReader bufin = new BufferedReader(in);
				while ((str = bufin.readLine()) != null) {
					String s1 = (String) str.substring(0, 7);
					//System.out.printf("!!!%s!!!\n", s1);
					if((s1.compareToIgnoreCase("ntvuser") != 0))
					//if(.compareToIgnoreCase("ntvuseraccount") != 0 && str.substring(0, 14).compareToIgnoreCase("ntvuserpassword") != 0)
					{
						System.out.printf("#### %s####\n", str);
						strBF.append(str);
						strBF.append("\r\n");
					}
				}
				bufin.close();
				
				String sNtvuseraccount = "ntvuseraccount="+textField_3.getText().trim()+"\r\n";
				String sNtvuserpassword = "ntvuserpassword=" + textField_4.getText().trim()+"\r\n";
				strBF.append(sNtvuseraccount);
				strBF.append(sNtvuserpassword);
				System.out.printf("[%s]\n%s \n%s ", strBF.toString(), sNtvuseraccount, sNtvuserpassword);
				BufferedWriter bufwrite = new BufferedWriter(new FileWriter(filename.getAbsoluteFile()));
				bufwrite.write(strBF.toString());
				bufwrite.flush();
				bufwrite.close();
			
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}	
			//提示信息
			JOptionPane.showMessageDialog(null,
					"文件已成功保存！", "提示信息",
					JOptionPane.INFORMATION_MESSAGE);
			
		}else if(e.getActionCommand().equals("Quit"))
		{
			System.exit(0);
		}
	}
}
