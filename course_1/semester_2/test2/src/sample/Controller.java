package sample;

import com.sun.org.apache.xml.internal.security.Init;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.RowConstraints;
import javafx.scene.paint.Paint;

import java.net.URL;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Observable;
import java.util.ResourceBundle;

public class Controller implements Initializable {
    private final int n = 2;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        GridPane gridpane = new GridPane();
        gridpane.getColumnConstraints().add(new ColumnConstraints(100));
        gridpane.getRowConstraints().add(new RowConstraints(100));

        Label btn = new Label("Test");
        GridPane.setConstraints(btn, 0, 0);
        gridpane.getChildren().add(btn);
    }
}